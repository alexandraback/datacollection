from itertools import product

def min_div(n):
    for i in range(2, 12):
        if n % i == 0:
            return i
    return 0

for case in range(int(input())):
    N, J = map(int, input().split())
    ans = []
    for var in product('01', repeat=N-2):
        var = ''.join(('1', ) + var + ('1', ))
        divs = [min_div(int(var, i)) for i in range(2, 11)]
        if all(divs):
            ans.append(' '.join(map(str, [var, ] + divs)))
            if len(ans) == J:
                break
    print('Case #1:')
    print('\n'.join(ans))
