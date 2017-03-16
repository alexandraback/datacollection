if __name__ == '__main__':
    file_in=open('C-small-attempt2.in','r')
    file_out=open('output.out','w')
    loop = file_in.readline()

    
    
    for a in range(int(loop)):
        
        R,C,M=map(int,file_in.readline().split(' '))

        field=[]

        file_out.write("Case #%d:\n"%(a+1))

        def select(field,x,y):
            return field[C*y+x]
                   
        def print_field(field):
            for j in range(R):
                for i in range(C):
                    file_out.write(select(field,i,j))
                file_out.write('\n')


        def update_field(field,x,y):
            f=field[:]
            f[y*C+x]='0'
            if y+1<R and select(field,x,y+1)!='0':
                f[(y+1)*C+x]='.'
            if x+1<C and select(field,x+1,y)!='0':
                 f[y*C+x+1]='.'
            if y+1<R and x+1<C and select(field,x+1,y+1)!='0':
                f[(y+1)*C+x+1]='.'
            if y-1>=0 and select(field,x,y-1)!='0' :
                f[(y-1)*C+x]='.'
            if x-1>=0 and select(field,x-1,y)!='0':
                f[(y)*C+x-1]='.'
            if y-1>=0 and x-1>=0 and select(field,x-1,y-1)!='0':
                f[(y-1)*C+x-1]='.'
            if y+1<R and x-1>=0 and select(field,x-1,y+1)!='0':
                f[(y+1)*C+x-1]='.'
            if y-1>=0 and x+1<C and select(field,x+1,y-1)!='0':
                f[(y-1)*C+x+1]='.'
            return f


        def generate_fields(field):
            zero_loc=[i for i,val in enumerate(field) if val=='0']
            output=[]
            for loc in zero_loc:
                x,y=loc%C,(loc-loc%C)/C
                if x+1<C and field[y*C+x+1]=='.':
                    output.append(update_field(field,x+1,y))
                if y+1<R and field[(y+1)*C+x]=='.':
                    output.append(update_field(field,x,y+1))
            return output

        def recursive_check(field):
            if field.count("*") ==M:
                for i, val in enumerate(field):
                    if val=='0':
                        field[i]='.'
                field[0]='c'
                print_field(field)
                raise Exception
            elif field.count("*")<M:
                return
            else:
                loc_list=generate_fields(field)
                for loc in loc_list:
                    recursive_check(loc)


        for temp in range(R*C):
            field.append('*')

        field[0]='.'


        if field.count('*')==M:
            field[0]='c'
            print_field(field)
        else:
            field=update_field(field,0,0)
            try:
                recursive_check(field)
                file_out.write("Impossible\n")
            except Exception:
                pass




        #print total_time
        #file_out.write ("Case #%d: %f\n"%(a+1,total_time))

    file_in.close()
    file_out.close()


