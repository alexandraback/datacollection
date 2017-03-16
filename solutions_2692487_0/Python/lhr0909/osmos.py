def check_add(A, motes):
    result = 0
    current = A
    while len(motes) > 0:
        mote = motes.pop(0)
        if mote < current:
            current += mote
        else:
            temp = mote - current + 1
            if temp < current:
                #add a mote of the max size it can take
                current += (current - 1) + mote
                result += 1
            else:
                #add motes until I can get them all
                while current <= mote:
                    current += current - 1
                    result += 1
                current += mote
    return result


def check_remove(A, motes):
    result = 0
    current = A
    while len(motes) > 0:
        mote = motes.pop(0)
        if mote < current:
            current += mote
        else:
            temp = mote - current + 1
            if temp < current:
                #add a mote of the max size it can take
                current += (current - 1) + mote
            #otherwise remove
            result += 1
    return result


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = 0
        A, N = map(int, fin.readline().strip().split(' '))
        motes = sorted(map(int, fin.readline().strip().split(' ')))
        print A, N, motes, "-->",
        if A == 1:
            answer = len(motes)
        else:
            ans1 = check_remove(A, motes[:])
            ans2 = check_add(A, motes[:])
            print "(%s, %s) --> " % (ans1, ans2),
            answer = min(ans1, ans2)
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    # solve("A-tiny")
    # solve("A-small-attempt0")
    # solve("A-small-attempt1")
    # solve("A-small-attempt2")
    solve("A-small-attempt3")
    # solve("A-large")