
import sys

def get_answer(cost, prod, goal):
    base = 2
    # math goes somewhere here
    # solution of time_to_get_goal_cookies < time_to_build_farm_and_get_goal_cookies
    farms_to_stop_at = int(goal / cost - base / prod) 
    farms_to_stop_at = max(farms_to_stop_at, 0)
    time_to_get_farms = 0
    for farm_no in xrange(farms_to_stop_at):
        time_to_get_farms += cost / (base + prod * farm_no)
    time_to_get_goal = goal / (base + farms_to_stop_at * prod)
    time_total = time_to_get_farms + time_to_get_goal
    return time_total
     

def solve(fd):
    case_count = int(fd.readline())
    solution = []
    for case_no in xrange(1, case_count + 1):
        cost, prod, goal = map(float, fd.readline().split())
        ans = get_answer(cost, prod, goal)
        solution.append("Case #%d: %0.7f" % (case_no, ans))
    return '\n'.join(solution)

def main():
    if sys.argv[1:]:
        fn = sys.argv[1]
        with open(fn, 'r') as fd:
            res = solve(fd)
        print(res)
    else:
        test()
        
def test():
    import StringIO
    test_case = """4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0
"""
    expected_out = """Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762
"""
    out = solve(StringIO.StringIO(test_case))
    #print out
    #print expected_out
    assert out.strip() == expected_out.strip()
    print("Test ok")
    
if __name__ == '__main__':
    main()