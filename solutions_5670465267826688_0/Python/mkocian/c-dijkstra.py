quat_mul_matrix = [
    [1, 2, 3, 4],
    [2, -1, 4, -3],
    [3, -4, -1, 2],
    [4, 3, -2, -1]
]

def quat_mul(a, b):
    sign = 1
    if a < 0:
        sign *= -1
    if b < 0:
        sign *= -1
    return sign * quat_mul_matrix[abs(a)-1][abs(b)-1]


ijk = quat_mul(quat_mul(2, 3), 4)

def debug(*args):
    print(*args)
    return

def find_prefix(string, value, X, rev=False):
    boundary_results = set()

    prefix_product = 1
    i = 0
    repeats = 1
    while True:
        if rev:
            prefix_product = quat_mul(string[i], prefix_product)
        else:
            prefix_product = quat_mul(prefix_product, string[i])

        #debug((repeats-1) * string + string[:i+1], prefix_product)
        if prefix_product == value:
            break
        i = i+1

        if i == len(string):
            if prefix_product in boundary_results:
                #debug("in boundary_results")
                break

            #debug(list(boundary_results))
            boundary_results.add(prefix_product)
            i = 0
            repeats += 1
            if repeats > X:
                #debug("not in string")
                break

    return (prefix_product == value, i + (repeats-1) * len(string))
        

T = int(input())

for t in range(T):
    L, X = map(int, input().split())

    string = [ord(x) - ord('i') + 2 for x in input().strip()]

    product = string[0]
    for q in string[1:]:
        product = quat_mul(product, q)
    string_product = product


    #opt?
    product2 = 1
    for i in range(X):
        product2 = quat_mul(product2, product)
    product = product2


    if product != ijk:
        #continue #!!!
        #debug("!ijk", product)
        print("Case #" + str(t+1) + ": NO")
        continue
    
    #debug(string, "*", X)
    #debug(L, X)

    found1, pos1 = find_prefix(string, 2, X)
    found2, pos2 = find_prefix(list(reversed(string)), 4, X, rev=True)

    #big = string * X

    #wi = 1
    #for q in big[:pos1+1]:
        #wi = quat_mul(wi, q)
    #wj = 1
    #for q in big[pos1+1:len(string) * X - pos2 - 1]:
        #wj = quat_mul(wj, q)
    #wk = 1
    #for q in big[len(string) * X - pos2 - 1:]:
        #wk = quat_mul(wk, q)
        


    if found1 and found2 and (pos1 + pos2 + 2) < (len(string) * X):
        #if wi != 2 or wj != 3 or wk != 4 or quat_mul(wi, quat_mul(wj, wk)) != product:
            #print((wi, wj, wk))

        print("Case #" + str(t+1) + ": YES")
    else:
        #print(found1, found2, "pos", pos1, pos2, pos1+pos2+2, "len", len(string) * X)
        print("Case #" + str(t+1) + ": NO")


        

