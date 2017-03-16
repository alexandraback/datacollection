consonants = set(map(chr, range(97, 97+26)))

consonants.remove('a')
consonants.remove('e')
consonants.remove('i')
consonants.remove('o')
consonants.remove('u')


def check_consonant(s, n):
    for i in xrange(len(s)):
        count = 0
        j = i
        while j < len(s) and s[j] in consonants:
            count += 1
            j += 1
        if count >= n:
            return True
    return False


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = 0
        L, n = fin.readline().strip().split(' ')
        n = int(n)

        for i in xrange(len(L)):
            for j in xrange(i+1, len(L)+1):
                substr = L[i:j]
                #print substr
                if check_consonant(substr, n):
                    answer += 1


        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    # solve("A-tiny")
    solve("A-small-attempt0")
    # solve("A-large")