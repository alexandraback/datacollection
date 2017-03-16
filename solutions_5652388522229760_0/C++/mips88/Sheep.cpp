#include <stdio.h>

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define FOR(i,m) for(int i=0;i<(int)(m);i++)
#define FOR2(i,n,m) for(int i=n;i<(int)(m);i++)
#define ITER(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

int nrTest;

class Solver{
        int m_test;
    protected:
        FILE* m_input;
        FILE* m_output;
    public:

        Solver():m_input(stdin),m_output(stdout)
        {
        }

        void setInput(FILE* in)
        {
            m_input = in;
        }

        void setOutput(FILE* out)
        {
            m_output = out;
        }

        void setTest(int test)
        {
            m_test = test;
        }

        void readAndSolve()
        {
            init();
            readInput();
            solve();
            fprintf(m_output,"Case #%d: ",m_test);
            writeOutput();
        }

        virtual void readInput()=0;
        virtual void solve()=0;


        virtual void writeOutput()=0;


        virtual void init()=0;
};

class SheepSolver:public Solver
{
        int nr;
        int solution;
        int digits[10];
    public:
        void init()
        {
            FOR(i,10)
            {
                digits[i]=false;
            }
        }

        void readInput()
        {
            fscanf(m_input,"%d",&nr);
        }

        void addDigits(int nr)
        {
            while (nr>0)
            {
                digits[nr%10]  = true;
                nr/=10;
            }
        }

        bool allDone()
        {
            int sum = 0 ;
            FOR(i,10)
            {
                sum+=digits[i];
            }


            return sum==10;
        }

        void solve()
        {
            if (nr==0)
            {
                solution = -1;
                return;
            }

            solution = 0;
            do{

                //printf("try:%d\n",nr*(solution+1));
                addDigits(nr*(solution+1));
                solution++;
            } while (!allDone());
            solution = nr*(solution);
        }

        void writeOutput()
        {
            if (solution == -1)
                fprintf(m_output,"INSOMNIA\n");
            else
                fprintf(m_output,"%d\n",solution);
        }
};

int main()
{
    FILE* f = fopen("input.txt","rt");
    FILE* fout = fopen("output.txt","wt");

    fscanf(f,"%d",&nrTest);
    FOR(i,nrTest)
    {
        SheepSolver solver;
        solver.setTest(i+1);
        solver.setInput(f);
        solver.setOutput(fout);
        solver.readAndSolve();
    }
    fclose(f);
    fclose(fout);
}
