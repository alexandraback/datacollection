from copy import copy, deepcopy
def solve(N, M):
    """ solve the problem """

    #ori_M = []
    #for row in M:
    #    r = []
    #    for elem in row:
    #        r.append(elem) 
    #    ori_M.append(r)
    ori_M = deepcopy(M)

    pos = -1
    line = []
    need_elem = -1
    for i in range(N):
        m_row = min(M, key=lambda x:x[i])
        m_index = M.index(m_row)
        m_elem = m_row[i]
        M.pop(m_index)
        found = False

        #print('->', m_row, m_elem)

        for m2_row in M:
            if m2_row[i] == m_elem:
                m2_index = M.index(m2_row)
                M.pop(m2_index)
                found = True
                break
        if not found: 
            need_elem = m_elem
            line = m_row
            pos = i

    l = [row[pos] for row in ori_M]
    l.append(need_elem)
    #print(l, line)
    for elem in line:
        l.pop(l.index(elem))

    l.sort()

    return ' '.join(str(i) for i in l)


def parse():
    """ parse input """
    N = int(input())
    M = []
    for i in range(2*N-1):
        M.append([int(j) for j in input().split()])

    return N, M


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
