import itertools

def same_subsum(numbers, N):
    for select in range(2, N): # from 2 to N-1
        for selected in itertools.combinations(numbers, select):
            selected_subset = set(selected)
            complement_set = numbers - selected_subset

            size_of_complement = len(complement_set)
            upper = select+1 if size_of_complement >= select else size_of_complement+1
            for sub_select in range(1, upper): # from 1 to upper-1
                for sub_selected in itertools.combinations(complement_set, sub_select):
                    subset = set(sub_selected)
                    if sum(selected_subset) == sum(subset):
                        return selected_subset, subset
    return None, None


if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as input_file:
        cases = int(input_file.next())
        print 'all cases', cases
        with open('result', 'wb') as output_file:
            for i in range(cases):
                print 'processing ', i
                data = [int(x) for x in input_file.next().split(' ')]
                N, numbers = data[0], set(data[1:])
                set1, set2 = same_subsum(numbers, N)
                output_file.write('Case #%d:\n'%(i+1))
                if set1 == None:
                    output_file.write('Impossible\n')
                else:
                    str1 = ' '.join((str(i) for i in set1))
                    output_file.write(str1+'\n')
                    str2 = ' '.join((str(i) for i in set2))
                    output_file.write(str2+'\n')

