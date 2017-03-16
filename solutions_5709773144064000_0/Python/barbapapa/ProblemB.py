__author__ = 'barbapapa'


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            C, F, X = [float(x) for x in f.readline().strip().split(' ')]
            cases.append((C, F, X))
    return cases


def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+': '+r+'\n')


def solve_case(data):
    C, F, X = data
    production = 2
    cur_time = 0
    while True:
        #don't buy any more farms
        time_to_finish = X/production
        #buy another farm
        time_to_next_farm = C/production
        time_to_finish_incl_farm = time_to_next_farm + X/(production+F)
        if time_to_finish_incl_farm < time_to_finish:
            production += F
            cur_time += time_to_next_farm
        else:
            cur_time += time_to_finish
            break
    return str(cur_time)


#case = (5000.0, 40.0, 20000.0)
#print(solve_case(case))
file_name = 'B-small-attempt0'
cases = read_input(file_name+'.in')
solution = [solve_case(x) for x in cases]
write_output(file_name+'.out', solution)
