def find_outfits(J,P,S,K):
    # Initialize combinations dictionary
    combinations = {} 
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
                combinations[(j,p,0)] = 0
                combinations[(j,0,s)] = 0
                combinations[(0,p,s)] = 0
    # Try all different outfits
    outfits_count = 0
    outfits = []
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
                if combinations[(j,p,0)] >= K or combinations[(j,0,s)] >= K or combinations[(0,p,s)] >= K:
                    continue
                else:
                    outfits.append('{0} {1} {2}'.format(j,p,s))
                    outfits_count += 1
                    combinations[(j,p,0)] += 1
                    combinations[(j,0,s)] += 1
                    combinations[(0,p,s)] += 1
    outfits = '\n'.join(outfits)
    return outfits_count, outfits

if __name__ == '__main__':
    T = int(input())
    for case in range(1,T+1):
        J,P,S,K = [int(n) for n in input().split()]
        N, outfits = find_outfits(J,P,S,K)
        print("Case #{0}: {1}".format(case,N))
        print(outfits)