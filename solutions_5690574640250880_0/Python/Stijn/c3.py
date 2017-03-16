f = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/c/in.in')
T = int(f.readline().strip())
lines = []
for i in range(T): lines.append(f.readline().strip().split(' '))


# pakt steeds degene met minste vrij
    # kijkt welke velden een nieuwe moet komen
        # vult aantal vrij bij dat nieuwe veld in
        # update alle omliggende velden, met 1 vrije minder
    

def addfield(field,r,c,x,y):
    
    fields = [key for key, val in field.items() if key[0] >= x-1 and key[1] >= y-1 and key[0] <= x+1 and key[1] <= y+1 and not (key[0]==x and key[1]==y)]
    
    totaal = (min(c,x+1)-max(1,x-1)+1)*(min(r,y+1)-max(1,y-1)+1);
    field[(x,y)] = totaal-len(fields)-1;
    
    if(len(fields)>0):
        for i in fields:
            field[(i[0],i[1])] -= 1
    return field
 
fo = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/c/out.out','wb');   

for i in range(T):
    r = int(lines[i][0]);
    c = int(lines[i][1]); 
    m = int(lines[i][2]);
    
    if(min(r,c)==1): first = [[(1,1),1]];
    else: first = [[(1,1),3]];
    
    field = dict(first)
    free = r*c-m-1;
    fout = 0;
    while free > 0:
        list2 =  [[key,val] for key, val in field.items() if (free==val or free>=val) and val>0]
        if(len(list2)>0):
            choose = min(dict(list2).items(), key=lambda x: x[1])
            list3 = [[key,val] for key, val in field.items() if (free==val)]
            if(len(list3)>0):                
                choose = max(dict(list3).items(), key=lambda x: x[1])
            if(free>=choose[1]):
                if((choose[0][0],choose[0][1]+1) not in field and choose[0][1]+1<=r):
                    field = addfield(field,r,c,choose[0][0],choose[0][1]+1);
                    free -= 1;
                if((choose[0][0]+1,choose[0][1]) not in field and choose[0][0]+1<=c):
                    field = addfield(field,r,c,choose[0][0]+1,choose[0][1]);
                    free -= 1;                
                if((choose[0][0]-1,choose[0][1]) not in field and choose[0][0]-1>0):
                    field = addfield(field,r,c,choose[0][0]-1,choose[0][1]);
                    free -= 1;          
                if((choose[0][0],choose[0][1]-1) not in field and choose[0][1]-1>0):
                    field = addfield(field,r,c,choose[0][0],choose[0][1]-1);
                    free -= 1;
                if((choose[0][0]-1,choose[0][1]+1) not in field and choose[0][0]-1>0 and choose[0][1]+1<=r):
                    field = addfield(field,r,c,choose[0][0]-1,choose[0][1]+1);
                    free -= 1;    
                if((choose[0][0]+1,choose[0][1]-1) not in field and choose[0][0]+1<=c and choose[0][1]-1>0):
                    field = addfield(field,r,c,choose[0][0]+1,choose[0][1]-1);
                    free -= 1;       
                if((choose[0][0]-1,choose[0][1]-1) not in field and choose[0][0]-1>0 and choose[0][1]-1>0):
                    field = addfield(field,r,c,choose[0][0]-1,choose[0][1]-1);
                    free -= 1;        
                if((choose[0][0]+1,choose[0][1]+1) not in field and choose[0][0]+1<=c and choose[0][1]+1<=r):
                    field = addfield(field,r,c,choose[0][0]+1,choose[0][1]+1);
                    free -= 1;    
            else:
                fout = 1                     
                break;
        else:
           fout = 1;
           break;
    #print field
    fo.write("Case #%d:\n" %(i+1))
    #fo.write("m %d free %d\n" %(m,(r*c-m)))
    if(fout==0):
        for q in range(1,r+1):
            line = [];
            for p in range(1,c+1):
                bla = [key for key, val in field.items() if key[0]==p and key[1]==q]
                #print bla
                if(p==1 and q==1): line.append("c");
                elif(len(bla)>0): line.append(".");
                else: line.append("*");
            fo.write(''.join(line));
            fo.write("\n");
    elif(m==0):
        for q in range(1,r+1):
            line = [];
            for p in range(1,c+1):
                if(p==1 and q==1): line.append("c");
                else: line.append(".");
            fo.write(''.join(line));
            fo.write("\n");
    else:
        fo.write("Impossible\n")
        
fo.close();
        