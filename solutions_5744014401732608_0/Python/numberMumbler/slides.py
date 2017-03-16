#!/usr/bin/env python


import sys


__outputTemplate = 'Case #{0}: {1}\n'


def hold(b, m):
    if m > 2*(b - 2) + 1:
        return
    slides = [[0] * b for _ in range(b)]
    if m % 2 == 1:
        slides[0][-1] = 1
        m -= 1
    for i in range(b - 1):
        if m == 0:
            break
        for j in range(i+1, b - 1):
            if m == 0:
                break
            m -= 0 if slides[i][j] else 1
            slides[i][j] = 1
            for k in range(j, b - 1):
                slides[k][k+1] = 1
    return slides


def action(inFile, outFile):
    case = 0
    t = int(inFile.readline())
    for case in range(1, t+1):
        b, m= [int(x) for x in inFile.readline().strip().split(' ')]
        # TODO: implement
        slides = hold(b, m)
        result = 'IMPOSSIBLE' if slides is None else 'POSSIBLE'
        outFile.write(__outputTemplate.format(case, result))
        if slides is not None:
            for r in slides:
                outFile.write(''.join(str(x) for x in r) + '\n')


def main():
    """
    command line arguments are:
        input path
        output path (will overwrite existing)
    """
    assert len(sys.argv) == 3
    inputPath, outputPath = sys.argv[1:3]
    with open(inputPath, 'r') as inFile:
        with open(outputPath, 'w+') as outFile:
            action(inFile, outFile)


if __name__ == '__main__':
    main()
