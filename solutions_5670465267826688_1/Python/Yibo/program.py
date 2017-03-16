#!/usr/bin/python2.7

f = open('input.txt', 'r')
T = int(f.readline())

mult_table = [
    [0, 0, 0, 0, 0],
    [0, 1, 2, 3, 4],
    [0, 2, -1, 4, -3],
    [0, 3, -4, -1, 2],
    [0, 4, 3, -2, -1]
]

dic = {
    1: 1,
    'i': 2,
    'j': 3,
    'k': 4
}

def mul(v1, v2):
    # Returns the numerical value of v1 * v2
    sign_val = v1 * v2
    if sign_val >= 0:
        return mult_table[abs(v1)][abs(v2)]
    else:
        return -mult_table[abs(v1)][abs(v2)]

def get_product_table(L, arr, start, factor):
    # product[offset] will return products from start-th element
    # up to (start + offset)-th element
    product = [None] * L
    curr = arr[start]
    curr_val = mul(dic[curr], factor)
    product[0] = curr_val
    for offset in range(1, L):
        curr = arr[(start + offset) % L]
        curr_val = mul(curr_val, dic[curr])
        product[offset] = curr_val
    return product

def solve(L, X, arr):
    product_table = get_product_table(L, arr, 0, 1)
    loop_product = product_table[L - 1]
    # First check if product of all of them is -1
    all_product = 1
    for l in range(X % 4):
        all_product = mul(all_product, loop_product)
    if all_product != -1:
        print 'NO'
        return

    i_index = -1
    for index in range(4 * L):
        quotient = index / L
        remainder = index % L
        product = product_table[remainder]
        for q in range(quotient):
            product = mul(product, loop_product)
        if product == dic['i']:
            i_index = index
            break
    if i_index == -1:
        print 'NO'
        return
    else:
        quotient = (i_index / L) % 4
        factor = 1
        for q in range(quotient):
            factor = mul(factor, loop_product)
        start = (i_index + 1) % L
        j_product_table = get_product_table(L, arr, start, factor)
        j_index = -1
        for index in range(min(4 * L, L * X - i_index)):
            quotient = index / L
            remainder = index % L
            product = j_product_table[remainder]
            for q in range(quotient):
                product = mul(product, loop_product)
            if product == dic['j']:
                print 'YES'
                return
    print 'NO'

for t in range(T):
    (L, X) = f.readline().rstrip().split(' ')
    L = int(L)
    X = int(X)
    arr = f.readline().rstrip()
    assert L == len(arr)

    print "Case #" + str(t + 1) + ":",
    solve(L, X, arr)
