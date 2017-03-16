problem = 'D-small-attempt0'

fin = open(problem + '.in')
fout = open(problem + '.out', 'w')

def read_nums(cls=int):
    return [cls(x) for x in fin.readline().strip().split()]
    
def playwar(naomi, ken):
    ken = set(ken)
    points = 0
    for mass in naomi:
        kenbeats = [m for m in ken if m > mass]
        if kenbeats:
            ken.remove(min(kenbeats))
        else:
            ken.remove(min(ken))
            points += 1
    
    return points

def playdeceitfulwar(naomi, ken):
    ken = sorted(ken)
    naomi = sorted(naomi)
    N = len(naomi)
    points = 0
    naomimax = naomi[-1]
    while naomi:
        if naomi[-1] > ken[-1]:
            naomi = naomi[:-1]
            ken = ken[:-1]
            points += 1
        else:
            naomi = naomi[1:]
            ken = ken[:-1]
        
    return points

T = read_nums()[0]
for caseno in range(1, T+1):
    print("Case %d -----" % caseno)
    fin.readline()  # We don't need N
    naomi = read_nums(float)
    ken = read_nums(float)
    
    print(sorted(naomi))
    print(sorted(ken))
    
    war_pts = playwar(naomi, ken)
    dwar_pts = playdeceitfulwar(naomi, ken)
    
    fout.write("Case #%d: %d %d\n" % (caseno, dwar_pts, war_pts))