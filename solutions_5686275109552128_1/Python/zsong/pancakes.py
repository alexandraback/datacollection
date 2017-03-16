import math


def solve(n, plates):
    plates = sorted(plates, reverse=True)
    # print(plates)
    maxRound = plates[0]
    minTime = float('inf')
    for r in range(1, maxRound + 1):
        moveRound = 0
        for plate in plates:
            if plate <= r:
                break
            moveRound += math.ceil(plate / r) - 1
            # print(r, plate, moveRound)
        if moveRound + r < minTime:
            minTime = moveRound + r
            # print("Find", r, moveRound, minTime)

    return minTime


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        n = int(input())
        plates = [int(x) for x in input().split(' ')]
        print("Case #%i: %s" % (caseNr, solve(n, plates)))