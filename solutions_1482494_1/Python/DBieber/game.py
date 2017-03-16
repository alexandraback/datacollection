import os, sys

def main():
    f = open("in")
    T = int(f.readline()) #or read, readlines

    for case in range(T):
        ans = "Too Bad"

        N = int(f.readline())

        levels = []

        for lineno in range(N):
            line = f.readline().split()
            A = int(line[0]) #one star
            B = int(line[1]) #two stars
            levels.append([A, B, 0, lineno]) # 0=not plays, 1=1star earned, 2=2 stars earned

        stars = 0
        games = 0

        def play():
            done = True
            ones = []
            twos = []
            for level in levels:
                if level[2] != 2:
                    done = False
                if stars >= level[1] and level[2] == 0:
                    twos.append(level)
                elif stars >= level[0] and level[2] == 0:
                    ones.append(level)
                elif stars >= level[1] and level[2] == 1:
                    ones.append(level)
            return (done, ones, twos)

        done = False
        while not done:
            results = play()
            done = results[0]
            ones = results[1]
            twos = results[2]
            if done:
                ans = "%d" % games
                break
            if twos:
                for two in twos:
                    levels[two[3]][2] += 2
                    games+=1
                    stars+=2
                    # print stars, two[3], 'B'
            elif ones:
                one = ones[0]
                found = False
                for temp in ones:
                    if stars >= temp[1]:
                        one = temp
                        found = True
                    if not found and temp[1] > one[1]:
                        one = temp #choose level with highest cost of two stars
                levels[one[3]][2] += 1
                games+=1
                stars+=1
                # print stars, one[3], 'A'
            else:
                if not done:
                    ans = "Too Bad"
                    done = True
                    

        print "Case #%d: %s" %(case+1, ans)
    

if __name__ == '__main__':
    main()
