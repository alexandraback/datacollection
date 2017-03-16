import sys

def plan_attacks(tribes):
    plan = {}
    for t in tribes:
        for i in range(t['n']):
            day = t['d'] + i * t['d_d']
            strength = t['s'] + i*t['d_s']
            l, r = t['w'] + i * t['d_p'], t['e'] + i * t['d_p']
            if day not in plan:
                plan[day] = []
            plan[day].append({'strength':strength, 'l':l, 'r':r})
    return plan

def get_height(wall, l, r):
    for part in wall['parts']:
        if l >= part['l'] and r <= part['r']:
            return get_height(part, l, r)
    if l >= wall['l'] and r <= wall['r']:
        return wall['height']

def set_height(wall, l, r, h):
    for part in wall['parts']:
        if l >= part['l'] and r <= part['r'] and h > part['height']:
            set_height(part, l, r, h)
    if l == wall['l'] and r == wall['r'] and h > wall['height']:
        wall['height'] = h
    else:
        wall['parts'].append({'l':l, 'r':r, 'height':h, 'parts':[]})

def process_case():
    N = int(sys.stdin.readline().strip())
    tribes = []
    for i in range(N):
        d, n, w, e, s, d_d, d_p, d_s = [int(x) for x in sys.stdin.readline().strip().split(' ')]
        tribes.append({'d':d, 'n':n, 'w':w, 'e':e, 's':s, 'd_d':d_d, 'd_s':d_s, 'd_p':d_p})

    plan = plan_attacks(tribes)
    days_attacked = plan.keys()
    days_attacked.sort()

    wall = {'l':-sys.maxint-1, 'r':sys.maxint, 'height': 0, 'parts':[]}
    nb_succeeded = 0

    for d in days_attacked:
        to_build = []
        for attack in plan[d]:
            wall_height = get_height(wall, attack['l'], attack['r'])
            if wall_height < attack['strength']:
                nb_succeeded += 1
                to_build.append(attack)
        for attack in to_build:
            set_height(wall, attack['l'], attack['r'], attack['strength'])

    return nb_succeeded

def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        result = process_case()
        print 'Case #%d: %s' % (i + 1, result)

if __name__ == '__main__':
    main()
