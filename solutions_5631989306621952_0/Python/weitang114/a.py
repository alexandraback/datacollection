import fileinput


def run(s):
    res = s[0]
    for c in s[1:]:
        if ord(c) >= ord(res[0]):
            res = c + res
        else:
            res = res + c
    return res


def main():
    # inputs = [0, 1, 2, 11, 1692]
    inputs = []
    
    for line in fileinput.input():
        inputs.append(line.strip())
    inputs = inputs[1:]

    for i, s in enumerate(inputs):
        res = run(s)
        print 'Case #%d: %s' % (i+1, res)
            

if __name__ == '__main__':
    main()

