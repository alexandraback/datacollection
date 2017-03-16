#!/usr/bin/env python


import sys


__outputTemplate = 'Case #{0}: {1}\n'


def getOutfits(j, p, s, k):
    hold = [j, p, s]
    maxOut = j * p * k
    outfits = set()
    x = [0, 0, 0]
    for r in range(j * p * s +1):
        outfit = [1 if hold[i] == 1 else (x[i] % hold[i]) + 1 for i in range(len(hold))]
        outfits.add(' '.join(str(x) for x in outfit))
        if len(outfits) == maxOut:
            break
        x[len(x) - (r % len(x)) - 1] += 1
    return outfits


def action(inFile, outFile):
    t = int(inFile.readline())
    for case in range(1, t+1):
        j, p, s, k = [int(x) for x in inFile.readline().strip().split(' ')]
        outfits = getOutfits(j, p, s, k)
        outFile.write(__outputTemplate.format(case, len(outfits)))
        for outfit in outfits:
            outFile.write(outfit + '\n')


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
