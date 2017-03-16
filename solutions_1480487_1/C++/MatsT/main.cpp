#include <iostream>

using namespace std;

int main()
{
	int tests, contestants, judgescoresum;
	double audiencescoreleft;
    double judgescores[200];
    double adjusted[200];
    double results[200];
    cout.precision(15);
	cin >> tests;
	for(int i = 1; i<=tests; i++){
	    judgescoresum=0;
        cin >> contestants;
        for(int j=0;j<contestants;j++){
            cin >> judgescores[j];
            adjusted[j] = judgescores[j];
            results[j]=0;
            judgescoresum += judgescores[j];
        }
        audiencescoreleft = judgescoresum;
        for(int k=0;k<=200;k++){
            int count=0;
            for(int j=0;j<contestants;j++){
                if(adjusted[j]==k){
                    count++;
                }
            }
            double addamount = 1;
            bool last=false;
            if(count>=audiencescoreleft){
                addamount=audiencescoreleft/count;
                last=true;
            }
            audiencescoreleft-=addamount*count;
            for(int j=0;j<contestants;j++){
                if(adjusted[j]==k){
                    adjusted[j]+=addamount;
                }
            }
            if(last){
                break;
            }
        }
        for(int j=0;j<contestants;j++){
            results[j]=100*(adjusted[j]-judgescores[j])/judgescoresum;
        }
        cout << "Case #" << i << ":";

        for(int j=0;j<contestants;j++){
            cout << " " << results[j];
        }
        cout << endl;
	}
}
