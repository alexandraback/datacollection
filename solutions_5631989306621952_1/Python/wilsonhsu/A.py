

def solve(S):
    word = S[0]
    for c in S[1:]:
        if c >= word[0]:
            word = c + word
        else:
            word = word + c
    return word

def run(name):
    f = open('{0}.in'.format(name), 'r')
    g = open('{0}.out'.format(name), 'w')

    T = int(f.readline())
    for t in range(T):
        S = f.readline().strip()
        word = solve(S)
        g.write("Case #{0}: {1}\n".format(t+1, word))

    f.close()
    g.close()

if __name__ == '__main__':
    run('A-large')
