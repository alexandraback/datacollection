def main():
    ifile = open('d.txt', 'r')
    ofile = open('d.out', 'w')

    T = int(ifile.readline().split()[0])

    for k in range(1, T+1):
        n = int(ifile.readline().split()[0])
        naomi = [float(x) for x in (ifile.readline().split())]
        ken = [float(x) for x in (ifile.readline().split())]
        
        war_score = n
        naomi2 = sorted(naomi)
        ken2 = sorted(ken)
        for i in range (0, n):
            for j in range (0, len(ken2)):
                if (ken2[j] > naomi2[i]):
                    war_score = war_score - 1
                    ken2.pop(j)
                    break

        game_score = n
        naomi2 = sorted(naomi)
        ken2 = sorted(ken)
        
        for i in range (0, n):
            if (ken2[0] > naomi2[0]):
                ken2.pop(len(ken2)-1)
                naomi2.pop(0)
                game_score = game_score -1
            else:
                ken2.pop(0)
                naomi2.pop(0)
                
        ofile.write('Case #%d: %d %d\n' %(k, game_score, war_score))
                
        

if __name__ == "__main__":
    main()
