import fileinput
f = fileinput.input()
T = int(f.readline())

def solve(S):
    last_word = ''
    first_char = 'A'
    for c in S:
        if first_char > c:
            last_word += c
        else:
            last_word = c + last_word
            first_char = c
    return last_word

for case in range(1,T+1):
    S = f.readline().strip()
    print "Case #%d: %s" % (case, solve(S))
