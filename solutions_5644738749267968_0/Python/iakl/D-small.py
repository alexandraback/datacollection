# IO file paths
file_in = "D-small-attempt0.in"
file_out = "D-small-attempt0.out"

class Blocks:
    weights = None
    taken = None

def GetSmallest(b):
    for i in range(0, len(b.taken)):
        if not b.taken[i]:
            return b.weights[i]
    return None

def RemoveSmallest(b):
    for i in range(0, len(b.taken)):
        if not b.taken[i]:
            b.taken[i] = True
            break

def GetLargest(b):
    n = len(b.taken)
    for i in range(0, n):
        if not b.taken[n - 1 - i]:
            return b.weights[n - 1 - i]
    return None

def RemoveLeastLarger(b, value):
    for i in range(0, len(b.taken)):
        if not b.taken[i] and b.weights[i] > value:
            b.taken[i] = True
            return True
    return False

def RemoveLargest(b):
    n = len(b.taken)
    for i in range(0, n):
        if not b.taken[n - 1 - i]:
            b.taken[n - 1 - i] = True
            break

# Solves the deceitful war problem
def SolveDeceitfulWar(N, Naomi, Ken):
    
    nb = Blocks()
    nb.weights = sorted(Naomi)
    nb.taken = []
    for _ in range(0, N):
        nb.taken.append(False)
    kb = Blocks()
    kb.weights = sorted(Ken)
    kb.taken = []
    for _ in range(0, N):
        kb.taken.append(False)
    
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
    kb = Blocks()
    kb.weights = sorted(Ken)
    kb.taken = []
    for _ in range(0, N):
        kb.taken.append(False)

    # Edge cases
    if GetSmallest(nb) > GetLargest(kb):
        return N
    if GetSmallest(kb) > GetLargest(nb):
        return 0

    score = 0
    for _ in xrange(0, N):
        value = GetLargest(nb)
        RemoveLargest(nb)
        if not RemoveLeastLarger(kb, value):
            score = score + 1
            RemoveSmallest(kb)
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
