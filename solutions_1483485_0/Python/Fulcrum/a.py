def input():
    with open('a.in') as file:
        lines_count = int(file.readline().strip())
        for i in xrange(lines_count):
            yield file.readline().strip()

def output(answers):
    with open('a.out', 'w') as file:
        for i, answer in enumerate(answers):
            file.write('Case #%s: %s\n' % (i + 1, answer))

def translate(string):
    dictionary = 'yhesocvxduiglbkrztnwjpfmaq'
    result = []
    for char in string:
        try:
            result.append(dictionary[ord(char) - ord('a')])
        except IndexError:
            result.append(char)
    return ''.join(result)

def main():
    translates = (translate(string) for string in input())
    output(translates)

if __name__ == '__main__':
    main()