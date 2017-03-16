import sys
import itertools


def find_subsets(numbers):
    d = {}
    largest_set = len(numbers) / 2
    matched_set = None
    for j in xrange(largest_set):
        for subset in itertools.combinations(numbers, j):
            total = sum(subset)
            
            # two sums matched
            if d.get(total):
                if not set(subset).intersection(set(d[total][0])):
                    d[total].append(subset)
                    matched_set = d[total]
                    break
            else:
                d[total] = [subset]

        if matched_set:
            break
    return matched_set

def main():
    file_name = sys.argv[1]
    input_file = open(file_name, "r").readlines()
    test_cases = int(input_file[0])

    for i in xrange(1, test_cases + 1):
        test_numbers = input_file[i].strip().split(" ")
        numbers = [int(j) for j in test_numbers[1:]]

        matches = find_subsets(numbers)

        print "Case #%s:" % (i)
        if matches:
            for match in matches:
                print " ".join(map(str, match))
        else:
            print "Impossible"


if __name__ == "__main__":
    main()
