__author__ = 'tegjyot'

import fileinput



def LARGESTLIST(list1):

    largest_list=0
    list1.insert(0,-1)
    for i in range(1,len(list1)):
        current=i
        dict={}
        count=1
        prev=current
        dict[current]=0
        start=i
        while count<len(list1)-1:
            prev=current
            current=list1[current]
            # print i ,  prev, current ,count
            if current in dict:
                if start==current:
                    # print count,' c'
                    break
                if prev!=list1[current]:
                    count=0
                    break
                else:
                    #check others
                    # print 'count1',count, i, prev, current
                    for k in range(1,len(list1)):
                        if k not in dict and list1[k]==prev:
                            count+=1
                            # print 'count',count, i
                            break
                    break
            else:
                # print i,prev,' op'
                dict[current]=0
                count+=1
        # print 'hi',i, current, count
        if count==len(list1)-1:
            if (start!=list1[current]) and current!=list1[list1[current]]:
                count=0
            # elif current!=list1[list1[current]]:
            #     count=0
            # print start, current,list1[current],'hi'
        if count>largest_list:
            largest_list=count
    return largest_list



if __name__ == "__main__":
    f = fileinput.input()
    T=int(f.readline())
    for case in range(1,T+1):
        N=int(f.readline())
        list1=[int(i) for i in f.readline().strip().split()]
        largest_list1=LARGESTLIST(list1)
        print("Case #{0}: {1}".format(case, largest_list1))