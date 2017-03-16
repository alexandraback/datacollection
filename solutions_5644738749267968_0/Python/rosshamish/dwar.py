"""
Google Code Jam
Online Qualifying Round

Problem D - Deceitful War
"""
def main():
    INFILENAME = 'D-small-attempt0.in'
    OUTFILENAME = 'D-small-attempt0.out'
    
    infile = open(INFILENAME)
    cases = int(infile.readline())
    
    outfile = open(OUTFILENAME, 'w')
    
    for case in range(1, cases+1):
        numblocks = int(infile.readline())
        naomis = [float(x) for x in infile.readline().split()]
        kens = [float(x) for x in infile.readline().split()]
        
        warpoints = playWar(numblocks, naomis, kens)
        dwarpoints = playDeceitfulWar(naomis, kens)
        
        print('\nCase #{}'.format(case))
        print('naomis: {}, kens: {}'.format(sorted(naomis), sorted(kens)))
        print('dwar: {}, war: {}'.format(dwarpoints, warpoints))
        
        outfile.write('Case #{}: {} {}\n'.format(case, dwarpoints, warpoints))


def playWar(numblocks, naomis, kens):
    """
    N: Always play your largest
    K: Always play your smallest larger one if you have it.
       If you don't, play your smallest to get rid of it.
    """
    pts_naomi, pts_ken = 0, 0
    naomis, kens = sorted(naomis), sorted(kens)
    for turn in range(numblocks):
        if kens[-1] > naomis[-1]:
            # Naomi plays her largest, ken beats it with his
            # smallest one that is larger than it
            i = len(kens)
            while kens[i-1] > naomis[-1]:
                if i-1 < 0:
                    break
                i -= 1
            
            del naomis[-1]
            del kens[i]
            
            pts_ken += 1
        else:
            # Naomi plays her largest, ken can't beat it
            # Ken plays his smallest
            del naomis[-1]
            del kens[0]
            
            pts_naomi += 1
    return pts_naomi

def playDeceitfulWar(naomis, kens):
    """
    N: Play your largest if it will get you a point
       Otherwise, play your smallest and claim it's in between
         the masses of his 1st and 2nd largest
    K: Play your smallest larger one if you have it.
       If you don't, play your smallest to get rid of it.
    """
    naomis, kens = sorted(naomis), sorted(kens)
    
    if len(naomis) == 1:
        if naomis[0] > kens[0]:
            return 1
        else:
            return 0
    
    # Naomi: play your worst block that can still beat
    #        ken's min, and claim it's better than his max
    try:
        bestworst = min(block for block in naomis if block > kens[0])
        naomis.remove(bestworst)
        del kens[0]
        
        return 1 + playDeceitfulWar(naomis, kens)
    except:
        # Naomi has not blocks better than his worst block. Oh well,
        # give up these points
        del naomis[0]
        worstbest = min(block for block in kens if block > naomis[0])
        kens.remove(worstbest)
        
        return playDeceitfulWar(naomis, kens)
    
    
    
    
    
    
    
    
    
    
    
    
    
main()