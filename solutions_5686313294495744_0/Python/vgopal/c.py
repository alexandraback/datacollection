import itertools

def answer(lines):
    for num_fake in xrange(len(lines), 0, -1):
        # print num_fake
        for fakes in itertools.combinations(lines, num_fake):
            fakes = set(fakes)
            left_words = set()
            right_words = set()
            works = True
            for line in lines:
                if line not in fakes:
                    left, right = line.split()
                    left_words.add(left)
                    right_words.add(right)
            for line in fakes:
                left, right = line.split()
                if left not in left_words or right not in right_words:
                    works = False
                    break
            if works:
                return num_fake
    return 0

input_file = open('c-small.txt')
num_cases = int(input_file.readline())
case_num = 1
while case_num <= num_cases:
    N = int(input_file.readline().strip())
    lines = [input_file.readline().strip() for _ in xrange(N)]
    print "Case #{}: {}".format(case_num, answer(lines))
    case_num += 1
