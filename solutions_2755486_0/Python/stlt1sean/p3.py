import sys
import pprint


def work(n, tribes):
    count = 0
    wall_width = 20000
    wall = [0]*(wall_width*2+1) #-100..100-1 index+wall_width
    # wall_width=3 wall [-3..-2, -2..-1, -1..0, 0..1, 1..2, 2..3]
    # wall[wall_width] => [0..1]
    while True:
        tmin = 676060*sys.maxint
        for t in tribes:
            if t['count'] >= t['num']:
                continue
            nexttime = t['count']*t['delta_day'] + t['day']
            if nexttime < tmin:
                tmin = nexttime
        today = []
        for t in tribes:
            if t['count'] >= t['num']:
                continue
            nexttime = t['count']*t['delta_day'] + t['day']
            if nexttime == tmin:
                today.append(t)
        if len(today) == 0:
            break
        #print 'Attack on ',tmin
        oldwall = list(wall)
        for nextt in today:
            attack = False
            west = nextt['west'] + nextt['count']*nextt['delta_dis']
            east = nextt['east'] + nextt['count']*nextt['delta_dis']
            stre = nextt['str'] + nextt['count']*nextt['delta_str']
            #east is included
            for i in range(west, east):
                ind = i + wall_width
                if (ind < 0) or (ind >= wall_width*2):
                    continue
                if oldwall[ind] < stre:
                    attack = True
                    if wall[ind] < stre:
                        wall[ind] = stre # update wall
            nextt['count'] = nextt['count']+1
            if attack:
                count = count + 1
            #print west,'..',east, ':', stre, attack

        #print wall
    return count
    
if __name__=='__main__':
    fin = open('C-small-attempt2.in')
    #fin = open('c.in')
    fout = open('c.out','wt')
    #fout = sys.stdout
    line = fin.readline()
    t = int(line)
    for i in range(t):
        n = int(fin.readline().strip())
        tribe = []
        for j in range(n):
            lines = fin.readline().strip().split()
            t = {}
            t['day'] = int(lines[0])
            t['num'] = int(lines[1])
            t['west'] = int(lines[2])
            t['east'] = int(lines[3])
            t['str'] = int(lines[4])
            t['delta_day'] = int(lines[5])
            t['delta_dis'] = int(lines[6])
            t['delta_str'] = int(lines[7])
            t['count'] = 0
            tribe.append(t)
        fout.write('Case #%d: %s\n' %(i+1,work(n,tribe)))
    fout.close()
