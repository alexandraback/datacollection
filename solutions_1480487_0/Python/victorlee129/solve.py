def case():
    n,data=raw_input().split(None,1)
    num=n=int(n)

    points=map(int,data.split())

    sum_=point=sum(points)

    Done=False

    ans=[-1]*n

    while not Done:

        delta=(point+sum_)/float(num)

        Done=True


        for i in range(n) :
            if points[i]>delta :

                Done=False

                sum_-=points[i]
                points[i]=-1

                num-=1


    delta=(point+sum_)/float(num)

    ans=[ (delta-points[i])/point if points[i]>-1 else 0 for i in range(n) ]

    return ' '.join(map(str,[100*i for i in ans]))
                


for i in range(int(raw_input())):

    print 'Case #{}: {}'.format(i+1,case())
