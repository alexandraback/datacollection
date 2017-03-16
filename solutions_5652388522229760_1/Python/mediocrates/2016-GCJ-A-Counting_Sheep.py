def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            T = int(f.readline().strip())
            for i in range(1, T+1):
                N = int(f.readline().strip())
                if N == 0:
                    print "Case #%d: INSOMNIA" % i
                    continue
                not_seen = range(10)
                count = 0
                while not_seen:
                    count += N
                    for digit in list(set(map(int, list(str(count))))):
                        if digit in not_seen:
                            not_seen.remove(digit)
                print "Case #%d: %d" % (i, count)

if __name__ == '__main__':
    main()