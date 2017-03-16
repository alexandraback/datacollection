import sys

num_cases = int(sys.stdin.readline())

for case in range(1, num_cases+1):
    A, B = map( int, sys.stdin.readline().split() )
    if A >= B:
        print "Case #%s: 0" % (case)
        continue
        
    num_recycle_pairs = 0
    for m in range(A+1, B+1):
        m_string = str(m)
        duplicate_recycle_num_map = {}
        for index in range( len(m_string)-1, 0, -1 ):
            recycle_num = int(m_string[index:] + m_string[0:index])            
            if duplicate_recycle_num_map.has_key(recycle_num):
                continue
            duplicate_recycle_num_map[recycle_num] = 0    
            if recycle_num < m and recycle_num >= A:
                num_recycle_pairs += 1
    print "Case #%s: %s" % (case, num_recycle_pairs)