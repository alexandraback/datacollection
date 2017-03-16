def parse(filename):
    input = open('%s.in' % filename, 'r')
    cases = int(input.readline())
    results = []
    for i in range(cases):
        t = int(input.readline())
        tribes = []
        for j in range(t):
            tribes.append(input.readline()[:-1].split(' '))
        result = process(tribes)
        results.append('Case #%s: %s\n' % (i + 1, result))
    input.close()
    output = open('%s.out' % filename, 'w')
    output.writelines(results)
    output.close()

def wall_sort(a, b):
    a_value = a['interval'][0]
    b_value = b['interval'][0]
    return a_value - b_value

def process(tribes):
    result = 0
    attacks = {}
    days = []
    wall = []
    for i, tribe in enumerate(tribes):
        di = int(tribe[0])
        ni = int(tribe[1])
        wi = int(tribe[2])
        ei = int(tribe[3])
        si = int(tribe[4])
        delta_di = int(tribe[5])
        delta_pi = int(tribe[6])
        delta_si = int(tribe[7])
        for j in range(0, ni):
            day = di + j * delta_di
            days.append(day)
            left = wi + j * delta_pi
            right = ei + j * delta_pi
            strength = si + j * delta_si
            attack = {'strength': strength, 'interval': [left, right]}
            attacks.setdefault(day, [])
            attacks[day].append(attack)
    days = list(set(days))
    days.sort()
    for day in days:
        for attack in attacks[day]:
            attack_left = attack['interval'][0]
            attack_right = attack['interval'][1]
            for section in wall:
                if section['strength'] >= attack['strength']:
                    section_left = section['interval'][0]
                    section_right = section['interval'][1]
                    if section_left <= attack_left and section_right >= attack_left:
                        attack_left = section_right
            if attack_right > attack_left:
                result += 1
        for attack in attacks[day]:
            wall.append(attack)
        wall.sort(wall_sort)
    return result

parse('C-small-attempt1')
