from numpy import matrix, linalg

def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    while (count <= num_of_tests):
        nclasses = int(fh.readline().strip())
        nparents = list()
        for c in range(nclasses):
            parents = map(int, fh.readline().strip().split())
            assert len(parents[1:]) == parents[0]
            nparents.append((c+1, parents[1:] if (parents[0] > 0) else [])) 

        assert len(nparents) == nclasses

        test_data[count] = dict(nparents)
        count = count + 1

    fh.close()
    return test_data

def find_parents(c, nparents):
    seen_parents = set()
    for p in nparents[c]:
        seen_parents.add(p)
        for np in find_parents(p, nparents):
            seen_parents.add(np)
    return seen_parents

def _execute_test(test_data):
    nparents = dict(test_data)
    multiple_parents_classes = filter(lambda c: len(nparents[c]) > 1, nparents.keys())
    #print nparents
    #print multiple_parents_classes
    
    if len(multiple_parents_classes) == 0:
        #print "No"
        return 'No'
    
    for c in multiple_parents_classes:
        #print "*** "
        seen_parents = set()
        
        for p in nparents[c]:
            #print c, p, seen_parents
            if p in seen_parents:
                #print "Yes"
                return 'Yes'

            seen_parents.add(p)
            pop = find_parents(p, nparents)
            #print c, p, seen_parents, pop
            for np in pop:
                if np in seen_parents:
                    #print "Yes"
                    return 'Yes'
                else:
                    seen_parents.add(np)

    #print "No"
    return 'No'

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