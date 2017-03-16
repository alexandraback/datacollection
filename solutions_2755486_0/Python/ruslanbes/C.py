#from operator import itemgetter, attrgetter

def Output(CaseN, res):
    outputLine = "Case #"+str(CaseN)+": "+str(res)
    fw.write(outputLine + "\n")


##################################
name = 'C-practice'
name = 'C-small'
#name = 'B-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()
T = int( lines.pop(0) )



for i in xrange(T):
    #print i
    N = int( lines.pop(0) )
    #tribes = []
    attacks = []
    for j in xrange(N):
        d, n, w, e, s, delta_d, delta_p, delta_s = map( lambda x: int(x), lines.pop(0).split(' ') )
        #tribes.append({'d': d, 'n': n, 'w': w, 'e': e, 's': s, 'delta_d': delta_d, 'delta_p': delta_p, 'delta_s': delta_s})
        #plan all attacks for this tribe
        for attack in xrange(n):
            attacks.append({'d':d, 'w': w, 'e': e, 's': s})
            d += delta_d
            w += delta_p
            e += delta_p
            s += delta_s

    attacks = sorted(attacks, key=lambda attack: attack['d'])
        
    last_d = attacks[0]['d'] # first ever attack
    wall = []
    raiseTo = [] # array to raise wall
    breaks = 0
    for attack in attacks:
        if last_d != attack['d']:
            for r in raiseTo:
                wall.append({'w': r['w'], 'e': r['e'], 's': r['s']})
            raiseTo = []
            last_d = attack['d']
        # now simulate attacks
        s1 = next((x for x in wall if x['s'] < attack['s'] and ( (x['w'] <= attack['w'] and x['e'] >= attack['w']) or (x['w'] <= attack['e'] and x['e'] >= attack['e']) or (x['w'] >= attack['w'] and x['e'] <= attack['e']) )  ), False)
        s2 = next((x for x in wall if x['s'] >= attack['s'] and (x['w'] <= attack['w'] and x['e'] >= attack['e']) ), False)
        #print s1, s2
        if s2 == False or s1 != False:
            breaks += 1
            raiseTo.append({'w': attack['w'], 'e': attack['e'], 's': attack['s']})
    Output(i+1, breaks)