def read_number(f):
    return int(f.readline().strip())


def compute(people_count):
    people_necessary = 0
    count = 0

    for shyness_level, people in enumerate(people_count):
        if count < shyness_level:
            people_necessary += shyness_level - count
            count = shyness_level
        count += people

    return people_necessary



def main():
    with open('A-large.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            most_shy, numbers = f.readline().split()
            print('Case #{}: {}'.format(test_case + 1, compute(list(map(int, numbers)))))

if __name__ == '__main__':
    main()
