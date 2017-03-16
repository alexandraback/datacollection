def cycle(number):
    """
    get a iterable sequence of cycled numbers
    the numbers are of the same length as the parameter
    """
    number_str = str(number)
    for i in range(len(number_str)):
        cycled = number_str[i:] + number_str[:i]
        if cycled[0] == '0':
            continue
        yield int(cycled)

def equivalent_class(number):
    """
    calculate the equivalent class of number for cycling
    i.e. the smallest in cycled sequence
    """
    eq = number
    for cycled in cycle(number):
        if cycled < eq:
            eq = cycled
    return eq

def num_cycled_pairs(number, low, high):
    """
    calculate the number of cycled pairs (n, m) in [low, high]
    in cycled sequence of number, n < m
    """
    num_of_cycled = len(set([n for n in cycle(number) if n >= low and n <= high]))
    num_of_pairs = num_of_cycled * (num_of_cycled - 1) / 2
    return num_of_pairs

def num_all_cycled_pairs(low, high):
    eq_classes = set()
    num_of_pairs = 0
    for n in xrange(low, high+1):
        eq_class = equivalent_class(n)
        if eq_class not in eq_classes:
            eq_classes.add(eq_class)
            num_of_pairs += num_cycled_pairs(n, low, high)
    return num_of_pairs

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as input_file:
        cases_num = int(input_file.next())
        with open('result', 'wb') as output_file:
            for i in range(cases_num):
                line = input_file.next()
                low, high = [int(token) for token in line.split(' ')]
                num_pairs = num_all_cycled_pairs(low, high)
                output_file.write("Case #%s: %s\n" % (i+1, num_pairs))

