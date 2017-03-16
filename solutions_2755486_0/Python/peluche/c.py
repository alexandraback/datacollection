#!/usr/bin/env python2.7
#

# naive version

di       = 0
ni       = 1
wi       = 2
ei       = 3
si       = 4
delta_di = 5
delta_pi = 6
delta_si = 7

wall = {}
attacks = {}

def gen_attacks(tribes):
    for tribe in tribes:
        # for each attack of the tribe
        for i in range(0, tribe[ni]): 
            day = tribe[di] + i*tribe[delta_di]
            if day not in attacks:
                attacks[day] = []
            wii = tribe[wi] + i*tribe[delta_pi]
            eii = tribe[ei] + i*tribe[delta_pi]
            sii = tribe[si] + i*tribe[delta_si]
            attacks[day].append([wii, eii, sii])
    #print attacks


def solve(tribes):
    worked = 0
    gen_attacks(tribes)
    #for day in sorted(attacks):
    for day in sorted(attacks.keys()):
        # check if attack worked
        for attack in attacks[day]:
            wii, eii, sii = attack
            # attack each slice
            for x in xrange(wii, eii):
                if sii > wall.get(x, 0):
                    # print 'worked: {}'.format(attack)
                    worked += 1
                    break
        # update wall at the end of the day
        for attack in attacks[day]:
            wii, eii, sii = attack
            for x in xrange(wii, eii):
                wall[x] = max(wall.get(x, 0), sii)
    return worked

def main():
    T = int(raw_input())
    for i in range(0, T):
        # clean globals
        global wall
        wall = {}
        global attacks
        attacks = {}

        N = int(raw_input())
        tr = [raw_input() for j in range(0, N)]
        tribes = []
        for tt in tr:
            tribes.append(map(int, [t for t in tt.split(' ')]))
        res = solve(tribes)
        print 'Case #{}: {}'.format(i+1, res)

if __name__ == '__main__':
    main()
