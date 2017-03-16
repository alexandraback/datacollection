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
    if len(carp) == 1:
        return math.sqrt((2 * d) / a)

    if carp[0][1] >= d:
        return math.sqrt((2 * d) / a)

    ttotal = 0
    stotal = 0
    myv = 0
    for i in range(len(carp) - 1):
        cp = carp[i]
        ncp = carp[i+1]

        dt = ncp[0] - cp[0]
        dx = ncp[1] - cp[1]
        carv = dx / dt

        if ncp[1] >= d:
            newt = (d - cp[1]) / carv

            olds = stotal
            stotal += (myv * newt) + (0.5 * a * newt * newt)
            if stotal >= d:
                ttotal += newt
            else:
                print myv
                print ttotal, (-myv + math.sqrt((myv * myv) + (2 * (d - olds) * a))) / a
                ttotal += (-myv + math.sqrt((myv * myv) + (2 * (d - olds) * a))) / a

            return ttotal

        stotal += (myv * dt) + (0.5 * a * dt * dt)
        if stotal >= ncp[1]:
            ttotal += dt
            stotal = ncp[1]
            myv = carv
        else:
            ttotal += dt
            myv += a * dt

    return ttotal

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
    
    output = open("test_outputs", "w")
    for test_id in xrange(1, num_of_tests + 1):
        test_data = test_data_set[test_id]
        test_result = _execute_test(test_data)
        output.write("Case #%s: %s\n" % (test_id, test_result))

    print "Done"
    output.close()

if __name__ == '__main__':
    main()