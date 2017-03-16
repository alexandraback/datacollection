__author__ = 'barbapapa'


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            N = int(f.readline().strip())
            naomi = [float(x) for x in f.readline().strip().split(' ')]
            ken = [float(x) for x in f.readline().strip().split(' ')]
            cases.append((naomi, ken))
    return cases


def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+': '+r+'\n')


def solve_case(data):
    naomi, ken = data
    #normal war
    naomi_war_pts = 0
    ken.sort()
    naomi.sort()
    ken_war = ken[:]
    for n in naomi:
        ken_wins = -1
        for k in ken_war:
            if k > n:
                ken_wins = k
                break
        if ken_wins != -1:
            ken_war.remove(ken_wins)
        else:
            naomi_war_pts += 1
            ken_war.remove(ken_war[0])

    #deceitful war
    naomi_decwar = naomi[:]
    ken_decwar = ken[:]
    naomi_decwar_ptr = 0
    while len(naomi_decwar)>0 and len(ken_decwar)>0:
        if naomi_decwar[-1] > ken_decwar[-1]:
            naomi_decwar_ptr += 1
            naomi_decwar.pop()
            ken_decwar.pop()
        else:
            naomi_decwar.remove(naomi_decwar[0])
            ken_decwar.pop()

    return str(naomi_decwar_ptr) + ' ' + str(naomi_war_pts)


file_name = 'D-small-attempt0'
cases = read_input(file_name+'.in')
solution = [solve_case(x) for x in cases]
write_output(file_name+'.out', solution)
