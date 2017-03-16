

#include <stdio.h>
#include <algorithm>

using namespace std;

int number_of_cases;

int main() {
    
    scanf("%d",&number_of_cases);
    
    for (int case_number=1;case_number<=number_of_cases;case_number++){
        int number_of_diners;
        int pancakes_on_plate[1005];
        scanf("%d",&number_of_diners);
        for (int i=0;i<number_of_diners;i++) scanf("%d",&pancakes_on_plate[i]);
        
        int answer=1000000000;
        
        for (int max_plate_size=1;max_plate_size<=1000;max_plate_size++){
            int minutes_for_cutting=0;
            
            for (int i=0;i<number_of_diners;i++) minutes_for_cutting+= ( (pancakes_on_plate[i] -1 ) / max_plate_size );
            
            answer=min(answer,max_plate_size+minutes_for_cutting);
        }
        
        printf("Case #%d: %d\n",case_number,answer);
        
    }
    return 0;
}
