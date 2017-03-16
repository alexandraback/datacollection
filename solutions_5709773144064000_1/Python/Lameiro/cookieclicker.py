from pprint import pprint

LIMIT_FACTORIES = 100000

def read_list_of(numtype):
    return map(numtype, raw_input().split())

# def calculate(c, f, x):
#     start_rate = 2
#
#     time_to_acquire_all = {0: 0}
#     total_time_to_objective = {0: x/start_rate}
#
#     for num in xrange(1, LIMIT_FACTORIES):
#         time_to_acquire_all[num] = time_to_acquire_all[num-1] + c/(start_rate + (num-1)*f)
#         total_time_to_objective[num] = time_to_acquire_all[num] + x/(start_rate + num*f)
#
#         # if num > 100000:
#         #     if total_time_to_objective[num - 2] < total_time_to_objective[num-1] < total_time_to_objective[num]: # we are degrading
#         #         break
#
#
#     the_min = min(total_time_to_objective.items(), key=lambda elem: elem[1])
#
#     return the_min

def calculate(c, f, x):
    start_rate = 2

    time_to_acquire_one = {num: c/(start_rate + (num-1)*f) for num in xrange(1, LIMIT_FACTORIES)}
    time_to_acquire_one[0] = 0

    time_to_acquire_all = {0: 0}
    for num in xrange(1, LIMIT_FACTORIES):
        time_to_acquire_all[num] = time_to_acquire_all[num-1] + time_to_acquire_one[num]

    #pprint(time_to_acquire_all)
    time_to_objective_without_acquisitions = {num: x/(start_rate + num*f) for num in xrange(0, LIMIT_FACTORIES)}

    #pprint(time_to_objective_without_acquisitions)
    total_time_to_objective = {num: time_to_acquire_all[num] + time_to_objective_without_acquisitions[num] for num in xrange(0, LIMIT_FACTORIES)}
    #pprint(total_time_to_objective)

    the_min = min(total_time_to_objective.values())

    return the_min

def main():
    for case_number in xrange(int(raw_input())):
        c, f, x = read_list_of(float)

        result = calculate(c, f, x)

        print 'Case #%d: %s' % (case_number+1, result)

main()

# for i in xrange(100):
#     print calculate(30.0, 1.0, 2.0)
#     print calculate(30.0, 2.0, 100.0)
#     print calculate(30.50000, 3.14159, 1999.19990)
#     print calculate(500.0, 4.0, 2000.0)

#print calculate(30.0, 1.0, 2.0)
#print calculate(1.0, 10.0, 100000.0)