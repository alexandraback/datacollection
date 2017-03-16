T = int(input())

for test in range(T):
    N = int(input())
    if N == 0:
        print('Case #' + str(test+1) + ': ' + 'INSOMNIA')
        continue
    digits_seen = set()
    multiple = 0
    product = 0
    while len(digits_seen) < 10:
        multiple += 1
        product += N
        new_digits = set([x for x in str(product)])
        digits_seen |= new_digits
    print('Case #' + str(test + 1) + ': ' + str(product))