def sign(x):

    # -1 -> 1
    # 1 -> -1

    if len(x) == 1: return '-'+x
    else: return x[1]

def not_sign(x):
    return x

def multiply(x, y):


    if len(x) != len(y):
        _convert = sign
    else:
        _convert = not_sign

    if len(x) > 1: x = x[1]
    if len(y) > 1: y = y[1]

    if x == '1': return _convert(y)
    if y == '1': return _convert(x)

    if x == 'i':
        if y == 'i': return _convert('-1')
        if y == 'j': return _convert('k')
        if y == 'k': return _convert('-j')
    if x == 'j':
        if y == 'i': return _convert('-k')
        if y == 'j': return _convert('-1')
        if y == 'k': return _convert('i')
    if x == 'k':
        if y == 'i': return _convert('j')
        if y == 'j': return _convert('-i')
        if y == 'k': return _convert('-1')

    raise Exception(x, y)

def solve(L, X, S):
    """ solve the problem """

    #print()
    #print('--------')
    #print(L, X, S)
    current = '1'
    want = 'i'
    done = False
    for i in range(X):
        for j in range(L):
            current = multiply(current, S[j])
            if current == want:
                if want == 'i':
                    want = 'j'
                    current = '1'
                    #print(i, j)
                elif want == 'j':
                    want = 'k'
                    current = '1'
                    #print(i, j)
                else:
                    want = ''
                    done = True
                    current = '1'
                    #print(i, j)
                    break
        if done: break

    if done:
        #print('done')
        #print(i, j)
        remain = '1'
        for _j in range(j+1, L):
            remain = multiply(remain, S[_j])

        remain_pairs = (X - 1 - i) % 4
        for _i in range(remain_pairs):
            for _j in range(L):
                remain = multiply(remain, S[_j])
        
        if remain == '1': return 'YES' 
        else: return 'NO'

    return 'NO'


def parse():
    """ parse input """

    L, X = [int(i) for i in input().split()]
    S = input()

    return L, X, S


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
