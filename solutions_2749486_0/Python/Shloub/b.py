# def bound(x,y,s,t):
#     if len(s)<13:
#         xx,yy=x,y+len(s)+1
#         ss=s+"N"
#         if abs(xx)<=100 and abs(yy)<=100 and t[xx+100][yy+100]==0:
#             t[xx+100][yy+100]=ss
#         bound(xx,yy,ss,t)
#         xx,yy=x,y-len(s)-1
#         ss=s+"S"
#         if abs(xx)<=100 and abs(yy)<=100 and t[xx+100][yy+100]==0:
#             t[xx+100][yy+100]=ss
#         bound(xx,yy,ss,t)
#         xx,yy=x-len(s)-1,y
#         ss=s+"E"
#         if abs(xx)<=100 and abs(yy)<=100 and t[xx+100][yy+100]==0:
#             t[xx+100][yy+100]=ss
#         bound(xx,yy,ss,t)
#         xx,yy=x+len(s)+1,y
#         ss=s+"W"
#         if abs(xx)<=100 and abs(yy)<=100 and t[xx+100][yy+100]==0:
#             t[xx+100][yy+100]=ss
#         bound(xx,yy,ss,t)

# t=[]
# for i in range(201):
#     t.append([0]*201)

# bound(0,0,"",t)

# print t


for i in range(int(raw_input())):
    x,y=map(int,raw_input().split())
    xx,yy=0,0
    s=""
    while xx<x:
        s+="WE"
        xx+=1
    while xx>x:
        s+="EW"
        xx-=1
    while yy<y:
        s+="SN"
        yy+=1
    while yy>y:
        s+="NS"
        yy-=1
    r=s
    print"Case #"+str(i+1)+":",r
