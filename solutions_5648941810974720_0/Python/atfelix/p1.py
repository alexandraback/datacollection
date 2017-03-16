from collections import Counter as C

def remove(c, n, s):
    for i in s:
        c[i] -= n
    return n

def stage1(c, counter):
    counter[0] = remove(c, c['Z'], 'ZERO')
    counter[2] = remove(c, c['W'], 'TWO')
    counter[4] = remove(c, c['U'], 'FOUR')
    counter[6] = remove(c, c['X'], 'SIX')
    counter[8] = remove(c, c['G'], 'EIGHT')

def stage2(c, counter):
    counter[1] = remove(c, c['O'], 'ONE')
    counter[3] = remove(c, c['R'], 'THREE')
    counter[5] = remove(c, c['F'], 'FIVE')
    counter[7] = remove(c, c['S'], 'SEVEN')
    counter[9] = remove(c, c['I'], 'NINE')

def solve(s):
    c = C(s)
    counter = [0 for i in range(10)]
    stage1(c, counter)
    stage2(c, counter)
    return ''.join(str(x) * counter[x] for x in range(10))

def main():
    for _ in range(int(input())):
        print('Case #%s: ' % str(_ + 1), end='')
        print(solve(input()))

if __name__ == '__main__':
    main()
