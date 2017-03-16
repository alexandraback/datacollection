def flip(string, _):
    num_changes = 0
    for i in range(len(string) - 1):
        if string[i] != string[i + 1]:
            num_changes += 1
    if string[-1] == '+':
        print('CASE #%d: %d' % (_, num_changes))
    else:
        print('CASE #%d: %d' % (_, num_changes + 1))

def main():
    for _ in range(int(input())):
        flip(input(), _ + 1)

if __name__ == '__main__':
    main()
