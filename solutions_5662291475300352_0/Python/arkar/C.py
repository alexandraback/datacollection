EPS = 0.00000001

if __name__ == "__main__":

    T = int(raw_input())

    memo = {}
    for cnt in xrange(T):
        n = int(raw_input())
        hikerInfo = []
        # STARTING POSITION, NUMBER OF CIRCLES, FASTEST POSITION

        for i in xrange(n):
            hikerInfo.append(map(int, raw_input().split()))

        indInfo =[]
        for start, numHikers, velocity in hikerInfo:
            for j in xrange(numHikers):
                indInfo.append({"start": start, "velocity": (velocity + j)})


        if len(indInfo) == 1:
            ans = 0
        else:
            firstLap1 = (360 - indInfo[0]["start"]) * indInfo[0]["velocity"]
            secondLap1 = firstLap1 + 360*indInfo[0]["velocity"]

            firstLap2 = (360 - indInfo[1]["start"]) * indInfo[1]["velocity"]
            secondLap2 = firstLap2 + 360*indInfo[1]["velocity"]

#            print firstLap1, secondLap1, firstLap2, secondLap2

            if secondLap1 <= firstLap2 or secondLap2 <= firstLap1:
                ans = 1
            else:
                ans = 0

            #



        print "Case #%s: %s" % (cnt + 1, ans)
