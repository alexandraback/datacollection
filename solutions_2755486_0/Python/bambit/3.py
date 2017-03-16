from operator import itemgetter

with open('C-small-attempt-0.in') as f:
    num_cases = int(f.readline().replace('\n', ''))    
    for case in xrange(1, num_cases+1):
        N = int(f.readline().replace('\n',''))
        tribes = []
        wall = [ 0 for x in xrange(-200, 200) ] 

        attack_list = {}
        successful_attacks = 0
        for tb in xrange(N):
            tribe = [ int(x) for x in f.readline().replace('\n','').split() ]
            
            for i in xrange(tribe[1]):
                dd = tribe[0] + tribe[5]*i
                if dd in attack_list:
                    attack_list[dd].append(tb)
                else:
                    attack_list[dd] = [ tb ]
            tribes.append(tribe)
          
        for day in sorted(attack_list.iteritems(), key=itemgetter(0)):
            patch = [ 0 for x in xrange(-200, 200) ] 
            for tb in day[1]:
                tribe = tribes[tb]
                attack_number = (day[0]-tribe[0])/(tribe[5])
                strength = tribe[4] + tribe[7]*attack_number 
                wloc = tribe[2] + tribe[6]*attack_number
                eloc = tribe[3] + tribe[6]*attack_number
                
                success = False
                for walloc in xrange(wloc, eloc):
                    if wall[walloc] < strength:
                        success = True
                        if patch[walloc] < strength:
                            patch[walloc] = strength
                if success:
                    successful_attacks += 1
            wall = map( max, zip(wall, patch))
        print 'Case #%d: %d' % (case, successful_attacks)
