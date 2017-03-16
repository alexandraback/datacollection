def read(filepath):
    with open(filepath, 'r') as infile:
        for line in infile:
            yield(line.strip())


def main():
    for inp in read('A-small-attempt0.in'):
        print(inp)


if __name__ == '__main__':
    main()

