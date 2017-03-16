file = open('a.txt', 'w')

def erase(str, delta):
    for i in str:
        char[i] -= delta

n = input()
for i in range(0, n):
    char = {}
    for j in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        char[j] = 0
    st = raw_input()
    for j in st:
        char[j] += 1
    ans = {}
    ans[0] = char['Z']
    erase('ZERO', char['Z'])
    ans[6] = char['X']
    erase('SIX', char['X'])
    ans[8] = char['G']
    erase('EIGHT', char['G'])
    ans[4] = char['U']
    erase('FOUR', char['U'])
    ans[2] = char['W']
    erase('TWO', char['W'])
    ans[7] = char['S']
    erase('SEVEN', char['S'])
    ans[5] = char['V']
    erase('FIVE', char['V'])
    ans[9] = char['I']
    erase('NINE', char['I'])
    ans[3] = char['R']
    erase('THREE', char['R'])
    ans[1] = char['O']

    answer = ""
    for j in range(0, 10):
        for k in range(0, ans[j]):
            answer += str(j)
    file.write('Case #%d: %s\n' % (i + 1, answer))
file.flush()
file.close()