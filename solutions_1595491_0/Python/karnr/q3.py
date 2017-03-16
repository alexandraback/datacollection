'''
Created on Apr 13, 2012

@author: karnr
'''
s1 = dict([(x, [3*x, 3*x - 1]) for x in range(11)])
s2 = dict([(x, [3*x - 2]) for x in range(11)])
s3 = dict([(x, [3*x - 3, 3*x - 4]) for x in range(11)])

def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    
    while (count <= num_of_tests):
        test_data[count] = map(int, fh.readline().strip().split())
        count += 1
        
    fh.close()
    return test_data

def _execute_test(test_input):
    scores = test_input[3:]
    assert len(scores) == test_input[0]
    num_of_surprising = test_input[1]
    best_score = test_input[2]
    s11 = set()
    [s11.update(s1[k]) for k in xrange(best_score, 11)]
    s11 = set(filter(lambda x: x > 0, s11))
    if best_score == 0:
        s11.add(0)
    
    s22 = set()
    [s22.update(s2[k]) for k in xrange(best_score, 11)]
    s22 = filter(lambda x: x > 0, s22)
    
    s33 = set()
    [s33.update(s3[k]) for k in xrange(best_score, 11)]
    s33 = filter(lambda x: x > 0, s33)
    
    sl = list()
    nsl = list()
    snsl = list()
    for s in scores:
        if (s in s11) and (s not in s22) and (s not in s33):
            nsl.append(s)
        if (s in s22) or ((s in s11) and (s in s33)):
            snsl.append(s)
        if (s in s33) and (s not in s11) and (s not in s22):
            sl.append(s)
    
    print (scores, num_of_surprising, best_score)
    print nsl, snsl, sl
    
    ans = 0
    if len(sl) >= num_of_surprising:
        ans += num_of_surprising + len(nsl) + len(snsl)
    else:
        ans += len(sl) + len(snsl) + len(nsl)

    print "Ans: %s" % ans
    print "======"
    return ans

def main():
    test_data_set = _parse_input("test_input")
    num_of_tests = len(test_data_set.keys())
    
    output = open("test_output", "w")
    for test_id in xrange(1, num_of_tests + 1):
        test_data = test_data_set[test_id]
        test_result = _execute_test(test_data)
        output.write("Case #%s: %s\n" % (test_id, test_result))
        
    output.close()
    
if __name__ == '__main__':
    main()