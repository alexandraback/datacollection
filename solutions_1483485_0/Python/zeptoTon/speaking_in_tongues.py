temp = {
    'a': 'y',
    'b': 'h',
    'c': 'e',
    'd': 's',
    'e': 'o',
    'f': 'c',
    'g': 'v',
    'h': 'x',
    'i': 'd',
    'j': 'u',
    'k': 'i',
    'l': 'g',
    'm': 'l',
    'n': 'b',
    'o': 'k',
    'p': 'r',
    'q': 'z',
    'r': 't',
    's': 'n',
    't': 'w',
    'u': 'j',
    'v': 'p',
    'w': 'f',
    'x': 'm',
    'y': 'a',
    'z': 'q'
}


def map_word(lines):
    result = ''
    for i in range(len(lines)):
        if lines[i] == ' ':
            result = result + ' '
        else:
            result = result + temp[lines[i]]
    return result


def main():
    f = open('A-small-attempt0.in', 'r')
    r = open('A-small-attempt0.in-result', 'w')

    while True:
        line = f.readline()
        if not line:
            break
        caseNum = int(line)
        for i in range(caseNum):
            lines = f.readline().rstrip()
            result_line = 'Case #' + str(i + 1) + ': ' + map_word(lines)
            r.write(result_line + '\n')
            print result_line

    f.close()
    r.close()


if __name__ == '__main__':
    main()
