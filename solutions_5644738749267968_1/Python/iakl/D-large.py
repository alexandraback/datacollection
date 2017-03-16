# IO file paths
file_in = "D-large.in"
file_out = "D-large.out"

class Blocks:
    weights = None
    taken = None
    n = None    # block count
    l = None    # left iterator
    r = None    # right iterator

def GetSmallest(b):
    if None == b.l:
        b.l = 0
    for i in range(b.l, b.n):
        if not b.taken[i]:
            b.l = i
            return b.weights[i]
    return None

def RemoveSmallest(b):
    if None == b.l:
        b.l = 0
    for i in range(b.l, b.n):
        if not b.taken[i]:
            b.l = i
            b.taken[i] = True
            break

def GetLargest(b):
    if None == b.r:
        b.r = b.n
    for i in range(b.r, 0, -1):
        if not b.taken[i - 1]:
            b.r = i
            return b.weights[i - 1]
    return None

def RemoveLeastLarger(b, value):
    if None == b.l:
        b.l = 0
    if None == b.r:
        b.r = b.n
    for i in range(b.l, b.r):
        if not b.taken[i] and b.weights[i] > value:
            b.taken[i] = True
            return True
    return False

def RemoveLargest(b):
    if None == b.r:
        b.r = b.n
    for i in range(b.r, 0, -1):
        if not b.taken[i - 1]:
            b.r = i
            b.taken[i - 1] = True
            break

# Solves the deceitful war problem
def SolveDeceitfulWar(N, Naomi, Ken):
    
    nb = Blocks()
    nb.weights = sorted(Naomi)
    nb.taken = []
    for _ in range(0, N):
        nb.taken.append(False)
    nb.n = N
    kb = Blocks()
    kb.weights = sorted(Ken)
    kb.taken = []
    for _ in range(0, N):
        kb.taken.append(False)
    kb.n = N
    
    # Edge cases
    if GetSmallest(nb) > GetLargest(kb):
        return N
    if GetSmallest(kb) > GetLargest(nb):
        return 0
    
    score = 0
    for _ in xrange(0, N):
        if GetSmallest(nb) < GetSmallest(kb):
            RemoveSmallest(nb)
            RemoveLargest(kb)
        else:
            RemoveSmallest(nb)
            RemoveSmallest(kb)
            score = score + 1
    return score

# Solves the optimal war problem
def SolveOptimalWar(N, Naomi, Ken):
    
    nb = Blocks()
    nb.weights = sorted(Naomi)
    nb.taken = []
    for _ in range(0, N):
        nb.taken.append(False)
    nb.n = N
    kb = Blocks()
    kb.weights = sorted(Ken)
    kb.taken = []
    for _ in range(0, N):
        kb.taken.append(False)
    kb.n = N

    # Edge cases
    if GetSmallest(nb) > GetLargest(kb):
        return N
    if GetSmallest(kb) > GetLargest(nb):
        return 0

    score = 0
    for _ in xrange(0, N):
        value = GetLargest(nb)
        if not RemoveLeastLarger(kb, value):
            score = score + 1
            RemoveSmallest(kb)
        RemoveLargest(nb)
    return score

# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        N = int(lines[i].rstrip())
        i = i + 1
        Naomi_values = lines[i].strip().split(' ')
        Naomi = []
        for j in range(0, N):
            Naomi.append(float(Naomi_values[j]))
        i = i + 1
        Ken_values = lines[i].strip().split(' ')
        Ken = []
        for j in range(0, N):
            Ken.append(float(Ken_values[j]))
        i = i + 1
        
        result = str(SolveDeceitfulWar(N, Naomi,Ken))
        result = result + ' '
        result = result + str(SolveOptimalWar(N, Naomi,Ken))
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')        
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
