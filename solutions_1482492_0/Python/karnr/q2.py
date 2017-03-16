import math
def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    while (count <= num_of_tests):
        (d, m, a) = map(float, fh.readline().strip().split())
        carp = list()
        for i in range(int(m)):
            carp.append(map(float, fh.readline().strip().split()))
        
        acc = map(float, fh.readline().strip().split())
        test_data[count] = (d, carp, acc)
        count = count + 1

    fh.close()
    return test_data

def run_test(d, a, carp):
    assert len(carp) <= 2

    if len(carp) == 1:
        return math.sqrt((2 * d) / a)

    else:
        if carp[0][1] >= d:
            return math.sqrt((2 * d) / a)
        dt = carp[1][0] - carp[0][0]
        dx = carp[1][1] - carp[0][1]
        carv = dx / dt
        newt = (d - carp[0][1]) / carv
        s = 0.5 * a * newt * newt
        if (s >= d):
            return newt
        else:
            return math.sqrt((2 * d) / a)

def _execute_test(test_data):
    (d, carp, acc) = test_data
    ans = list()
    for a in acc:
        ans.append(run_test(d, a, carp))
    print ans
    return "\n%s" % "\n".join(["%.10f" % x for x in ans])

def main():
    test_data_set = _parse_input("test_input")
    num_of_tests = len(test_data_set.keys())
    
    output = open("test_output", "w")
    for test_id in xrange(1, num_of_tests + 1):
        test_data = test_data_set[test_id]
        test_result = _execute_test(test_data)
        output.write("Case #%s: %s\n" % (test_id, test_result))

    print "Done"
    output.close()

if __name__ == '__main__':
    main()