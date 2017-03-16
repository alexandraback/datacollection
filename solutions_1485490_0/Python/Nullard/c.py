import os.path, glob
PROBLEM = os.path.basename(__file__)[0].upper()
DL_DIR = os.path.join(os.environ['USERPROFILE'], 'Downloads', PROBLEM)
if os.path.exists(DL_DIR + '-large.in'):
    INP_PATH = DL_DIR + '-large.in'
    OUT_PATH = DL_DIR + '-large.ot'
else:
    inputs = glob.glob(DL_DIR + '-small-attempt[0-9].in')
    maxnum = -1
    for inp_fn in inputs:
        if int(inp_fn[-4]) > maxnum: maxnum = int(inp_fn[-4])
    if maxnum > -1:
        INP_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.in'
        OUT_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.ot'
    else:
        INP_PATH = os.path.join('..', 'data', PROBLEM + '.in')
        OUT_PATH = os.path.join('..', 'data', PROBLEM + '.ot')

in_file = open(INP_PATH)
out_file = open(OUT_PATH, 'w')

from gmpy2 import mpz

def pp(s):
    out_file.write(s + '\n')
    print s

def best_route(m, n, total = mpz(0), mindex = 0, nindex = 0, partialm = mpz(0), partialn = mpz(0)):
    if mindex >= len(m) or nindex >= len(n): return total
    mval = m[mindex][1]
    nval = n[nindex][1]
    if m[mindex][0] == n[nindex][0]:
        if partialm > 0:
            added = min(n[nindex][1], mval - partialm)
            total += added
            partialm += added
            if partialm == mval:
                partialm = 0
                return best_route(m, n, total, mindex + 1, nindex, partialn = added)
            else:
                return max(best_route(m, n, total, mindex, nindex + 1, partialm), best_route(m, n, total, mindex + 1, nindex + 1))
        elif partialn > 0:
            added = min(m[mindex][1], n[nindex][1] - partialn)
            total += added
            partialn += added
            if partialn == nval:
                partialn = 0
                return best_route(m, n, total, mindex, nindex + 1, partialm = added)
            else:
                return max(best_route(m, n, total, mindex + 1, nindex, partialn=partialn), best_route(m, n, total, mindex + 1, nindex + 1))
        else:
            added = min(mval, nval)
            total += added
            if added == mval:
                return max(best_route(m, n, total, mindex + 1, nindex, partialn = added), best_route(m, n, total, mindex + 1, nindex + 1))
            else:
                return max(best_route(m, n, total, mindex, nindex + 1, partialm = added), best_route(m, n, total, mindex + 1, nindex + 1))
            
    return max(best_route(m, n, total, mindex + 1, nindex, partialn = partialn), best_route(m, n, total, mindex, nindex + 1, partialm = partialm))
               

NUM_CASES = int(in_file.readline().strip())
for case in range(1, NUM_CASES + 1):
    soln = ''
    n, m = map(int, in_file.readline().strip().split())
    n_data = []
    m_data = []
    ns = in_file.readline().strip().split()
    ms = in_file.readline().strip().split()
    best_count = mpz(0)
    for i in range(n):
        tp = int(ns.pop(1))
        cnt = mpz(ns.pop(0))
        if i > 0 and n_data[-1][0] == tp:
            n_data[-1][1] += cnt
        else: n_data.append([tp, cnt])
                    
        
    for i in range(m):
        tp = int(ms.pop(1))
        cnt = mpz(ms.pop(0))
        if i > 0 and m_data[-1][0] == tp:
            m_data[-1][1] += cnt
        else: m_data.append([tp, cnt])
#    n_index = mpz(0)
#    so_far = mpz(0)
#    best_total = mpz(0)
#    for i in range(m):
#        n_index = mpz(0)
#        so_far = mpz(0)
#        while so_far < m_data[i][1]:
#            if n_data[n_index][0] == m_data[i][0]:
#                so_far = min(m_data[i][1], n_data[n_index][1] + so_far)
#            else n_index += 1
    soln = str(best_route(m_data, n_data))
    
    pp('Case #' + str(case) + ': ' + str(soln))
out_file.close()
in_file.close()
