import itertools

def close_match():
    
    with open("B-small-attempt0.in") as file:
        lines = file.readlines()

    cases = []

    for index, test in enumerate(lines[1:]):

        c, j = test.strip().split()

        x = c.count("?")
        y = j.count("?")

        minimum = []
        min_diff = 10**20

        for x_item in itertools.product(list("9876543210"), repeat=x):
            for y_item in itertools.product(list("9876543210"), repeat=y):
                a = list(c)
                for item in x_item:
                    a[a.index("?")] = item
                b = list(j)
                for item in y_item:
                    b[b.index("?")] = item
                f = int(''.join(a))
                g = int(''.join(b))
                if abs(f-g) <= min_diff:
                    minimum = [''.join(a),''.join(b)]
                    min_diff = abs(f-g)

        result = ' '.join(minimum)

        cases.append("Case #{}: {}\n".format(index+1, result))

    with open("B-small-attempt0.out", 'w') as file:
        for string in cases:
            file.write(string)

close_match()
