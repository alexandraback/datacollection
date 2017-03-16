import sys

def limit(G):
    return 1 + (G-2)*(G-1) / 2


def test_max():
    for i in xrange(2,21):
        print i, limit(i)


def count_paths(matrix):
    return aux(0, matrix, set())

def aux(source, matrix, visited):
    visited = visited.union(set([source]))
    count = 0
    for i in xrange(len(matrix)):
        if not matrix[source][i]:
            continue

        # print 'Can go from node %s to node %s' % (source+1, i+1)        
        
        if i == source:
            return 'error-self reference'
        
        if i in visited:
            if matrix[source][i]:
                return 'inf'

        if i == len(matrix) - 1:
            count += 1
            continue

        c = aux(i, matrix, visited)
        if isinstance(c, str):
            return c
        count += c
    return count

def solve(B, M):
    # print 'B = %s, M = %s' % (B, M)
    
    ans = 'POSSIBLE'


    
    m_rem = M
    matrix = [[0 for j in xrange(B)] for i in xrange(B)]

    # Row 1
    matrix[0][B-1] = 1
    m_rem -= 1
    if m_rem == 0:
        return ans, matrix
    
    for i in xrange(1, B-1+1):
        for j in xrange(i+1, B-1+1):
            matrix[i-1][j-1] = 1


    adds = [1]
    for i in xrange(2,B):
        adds.append(sum(adds))

    for i in xrange(B-2, 1-1, -1):
        # print 'Paths remaining: %s' % (m_rem)
        # print 'Considering node %s' % (i+1)
        # adds = i
        #adds = 1 + (1 + i -1) * (i -1) / 2
        add = adds[i]
        # print 'Would add %s paths to B' % (add)
        
        if m_rem >= add:
            # print 'Connecting node %s to B' % (i+1)
            # print 'Which adds %s paths to B' % (add)
            matrix[i][B-1] = 1
            m_rem -= add
        if m_rem == 0:
            return ans, matrix
        
    return 'IMPOSSIBLE', None

        

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        B, M = map(int, sys.stdin.readline().strip().split())
        ans, matrix = solve(B, M)
        print 'Case #%s: %s' % (i+1, ans)
        if ans == 'POSSIBLE':
            for row in matrix:
                print ''.join(str(el) for el in row)
            count = count_paths(matrix)
            # print 'Real count:', count
            assert count == M

                
if __name__ == '__main__':
    main()
    #test_max()
