"""C
   Google CodeJam 2013
"""

from datetime import datetime

def success(attack, wall):
    att = [attack.copy()]
    #print "Wall:",wall
    #print "Attack:", att
    for segment in wall:
        for attsegment in att:
            if segment['s'] >= attsegment['s']:  #wall segment is stronger than attack segment
                if segment['e'] >= attsegment['w'] and segment['e'] <= attsegment['e'] and segment['w'] <= attsegment['w']:
                    attsegment['w'] = segment['e']+1
                elif segment['w'] <= attsegment['e'] and segment['w'] >= attsegment['w'] and segment['e'] >= attsegment['e']:
                    attsegment['e'] = segment['w']-1
                elif segment['e'] >= attsegment['w'] and segment['e'] <= attsegment['e'] and segment['w'] <= attsegment['e'] and segment['w'] >= attsegment['w']:
                    attsegment['e'] = segment['w']-1
                    att.append({'w':attsegment['e']+1,'e':segment['e'],'s':attsegment['s']})
                elif segment['e'] >= attsegment['w'] and segment['w'] <= attsegment['w']:
                    attsegment['e'] = attsegment['w']  #mark for remove
        if attsegment['w'] >= attsegment['e']:
            #print "Removing attack segment", attsegment
            att.remove(attsegment)
            if not att:
                break  #don't check rest of wall - no attack left
        #print "Attack",att
    for attsegment in att:
        if attsegment['w'] < attsegment['e']:
            #print "Success (remaining):",att
            return True
    #print "Failed (remaining):",att
    return False

def routine(tribes):
    wall = []
    count = 0
    #expand attacks
    attacks = []
    for tribe in tribes:
        d = tribes[tribe]['d']
        w = tribes[tribe]['w']
        e = tribes[tribe]['e']
        s = tribes[tribe]['s']
        dd = tribes[tribe]['dd']
        dp = tribes[tribe]['dp']
        ds = tribes[tribe]['ds']
        for attack in xrange(tribes[tribe]['n']):
            attacks.append({'d':d, 'w':w, 'e':e, 's':s})
            d+=dd
            w+=dp
            e+=dp
            s+=ds

    attacks.sort(key=lambda a:a['d'])
    #print attacks
        
    #attack/check/build wall
    prevday = -1
    building = []
    for attack in attacks:
        if attack['d'] != prevday:
            if building:
                wall.extend(building)
                building = []
            prevday = attack['d']
        
        if success(attack, wall):
            count += 1
            building.append({'w':attack['w'],'e':attack['e'],'s':attack['s']})
        
    
    return count

if __name__ == '__main__':
    filename = "C-small-attempt4"  #C-large
    f = open(filename + ".in")
    fo = open(filename + ".out", "w")

    print datetime.now()

    c = int(f.readline().strip())
    print c, "cases"
    for case in xrange(c):
        N = [int(x) for x in f.readline().split()][0]
        
        print N
        
        tribes = {}
        for tribe in xrange(N):
            d, n, w, e, s, dd, dp, ds = [int(x) for x in f.readline().split()]
            tribes[tribe] = {'d':d,'n':n,'w':w,'e':e,'s':s,'dd':dd,'dp':dp,'ds':ds}
        

        print >>fo, "Case #%d: %s" % (case+1, routine(tribes))

    fo.close()
    f.close()
    print datetime.now()
