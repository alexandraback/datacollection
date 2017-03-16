#!/Library/Frameworks/Python.framework/Versions/3.3/bin/python3.3
# Codejam ID 2974486
# Run with parameter
# -p for preprocessing
# -s for small input
# -l for large input
# -m=<int> for multithreading


from GCJ import GCJ

from collections import deque

def parse(infile):
    N = GCJ.readint(infile)

    naomi = GCJ.readfloatarray(infile)
    ken = GCJ.readfloatarray(infile)
    return N,deque(sorted(naomi)), deque(sorted(ken))
    
def solve(data):
    N, naomi, ken = data
    n_min = naomi.popleft()
    k_min = ken.popleft()

    KEN = 0
    NAOMI = 1    
    MAX = 100
    
    order = [NAOMI for x in range(2*N)]
    for i in range(2*N):
        if n_min < k_min:
            order[i] = NAOMI
            if len(naomi) > 0:
                n_min = naomi.popleft()
            else:
                n_min = MAX
        else:
            order[i] = KEN
            if len(ken) > 0:
                k_min = ken.popleft()
            else:
                k_min = MAX
    
    # dec_war
    dec_war = 0
    ken_left_cnt = 0
    ken_all = 0
    naomi_cnt = 0
    for ch in order:
        if ken_all == N: # Es kommen keine Kens mehr, Naomi gewinnt den rest
            dec_war += (N-naomi_cnt)
            break
        else:        
            if ch == KEN:
                ken_left_cnt += 1
                ken_all += 1
            elif ch == NAOMI:
                naomi_cnt += 1
                if ken_left_cnt > 0: # Es gibt einen kleineren Ken, Noami macht sich gros und gewinnt
                    dec_war += 1
                    ken_left_cnt -= 1 
                else: # Naomi macht sich so groß, dass sie gegen den Größten verliert
                    ken_all += 1

    # war
    war = 0
    ken_right_cnt = 0
    ken_all = 0
    naomi_cnt = 0
    order.reverse()
    for ch in order:
        #if ken_all == N:
        #    war += (N-naomi_cnt-ken_right_cnt)
        #else:
        if ch == KEN:
            ken_right_cnt += 1
            ken_all += 1
        elif ch == NAOMI:
            naomi_cnt += 1
            if ken_right_cnt == 0:
                war += 1
                ken_all += 1
            else:
                ken_right_cnt -= 1
        
    return "%d %d" % (dec_war, war)



if __name__ == "__main__":
    GCJ('D', solve, parse, None).run()

