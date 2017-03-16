import copy

ri = lambda : raw_input().strip()
rim = lambda tp, deli: map(tp, ri().split(deli))

n = int(ri())

for i in xrange(0, n):
    m = int(ri())
    naomi = rim(float, ' ')
    ken = rim(float, ' ')
    
    war_naomi = sorted(copy.deepcopy(naomi), reverse=True)
    war_ken = sorted(copy.deepcopy(ken))
    war_naomi_win = 0
    
    while war_naomi:
        mass_naomi = war_naomi[0]
        del war_naomi[0]
    
        if max(war_ken) > mass_naomi:
            del war_ken[-1]
        else:
            del war_ken[0]
            war_naomi_win += 1
    
    
    deceitful_naomi = sorted(copy.deepcopy(naomi), reverse=True)
    deceitful_ken = sorted(copy.deepcopy(ken), reverse=True)
    deceitful_naomi_win = 0
    
    while deceitful_ken:
        mass_ken = deceitful_ken[0]
        del deceitful_ken[0]
        
        if max(deceitful_naomi) > mass_ken:
            del deceitful_naomi[0]
            deceitful_naomi_win += 1
        else:
            del deceitful_naomi[-1]

    
    print 'Case #{0}: {1} {2}'.format(i+1, deceitful_naomi_win, war_naomi_win)
    
    